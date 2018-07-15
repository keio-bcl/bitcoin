// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2017 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <chainparamsbase.h>

#include <tinyformat.h>
#include <util.h>

#include <assert.h>

const std::string CBaseChainParams::MAIN = "main";
const std::string CBaseChainParams::TESTNET = "test";
const std::string CBaseChainParams::REGTEST = "regtest";
const std::string CBaseChainParams::BSAFENET = "bsafenet";

void AppendParamsHelpMessages(std::string& strUsage, bool debugHelp)
{
    strUsage += HelpMessageGroup(_("Chain selection options:"));
    strUsage += HelpMessageOpt("-testnet", _("Use the test chain"));
    if (debugHelp) {
        strUsage += HelpMessageOpt("-regtest", "Enter regression test mode, which uses a special chain in which blocks can be solved instantly. "
                                   "This is intended for regression testing tools and app development.");
        strUsage += HelpMessageOpt("-bsafenet", "Enter segregated witness test mode on bsafenet. ");
    }
}

/**
 * Main network
 */
class CBaseMainParams : public CBaseChainParams
{
public:
    CBaseMainParams()
    {
        nRPCPort = 8332;
    }
};

/**
 * Testnet (v3)
 */
class CBaseTestNetParams : public CBaseChainParams
{
public:
    CBaseTestNetParams()
    {
        nRPCPort = 18332;
        strDataDir = "testnet3";
    }
};

/**
 * bsafenet
 */
class CBaseBSafeNetParams : public CBaseChainParams
{
public:
    CBaseBSafeNetParams()
    {
        nRPCPort = 34822;
        strDataDir = "bsafenet";
    }
};

/*
 * Regression test
 */
class CBaseRegTestParams : public CBaseChainParams
{
public:
    CBaseRegTestParams()
    {
        nRPCPort = 18443;
        strDataDir = "regtest";
    }
};

static std::unique_ptr<CBaseChainParams> globalChainBaseParams;

const CBaseChainParams& BaseParams()
{
    assert(globalChainBaseParams);
    return *globalChainBaseParams;
}

std::unique_ptr<CBaseChainParams> CreateBaseChainParams(const std::string& chain)
{
    if (chain == CBaseChainParams::MAIN)
        return std::unique_ptr<CBaseChainParams>(new CBaseMainParams());
    else if (chain == CBaseChainParams::TESTNET)
        return std::unique_ptr<CBaseChainParams>(new CBaseTestNetParams());
    else if (chain == CBaseChainParams::REGTEST)
        return std::unique_ptr<CBaseChainParams>(new CBaseRegTestParams());
    else if (chain == CBaseChainParams::BSAFENET)
        return std::unique_ptr<CBaseChainParams>(new CBaseBSafeNetParams());
    else
        throw std::runtime_error(strprintf("%s: Unknown chain %s.", __func__, chain));
}

void SelectBaseParams(const std::string& chain)
{
    globalChainBaseParams = CreateBaseChainParams(chain);
}

std::string ChainNameFromCommandLine()
{
    bool fRegTest = gArgs.GetBoolArg("-regtest", false);
    bool fTestNet = gArgs.GetBoolArg("-testnet", false);
    bool fBSafeNet = gArgs.GetBoolArg("-bsafenet", false);

    if (fTestNet && fRegTest)
        throw std::runtime_error("Invalid combination of -regtest and -testnet.");
    if ((int)fRegTest + (int)fTestNet + (int)fBSafeNet > 1)
        throw std::runtime_error("Invalid combination of -regtest, -testnet, -bsafenet.");
    if (fRegTest)
        return CBaseChainParams::REGTEST;
    if (fTestNet)
        return CBaseChainParams::TESTNET;
    if (fBSafeNet)
        return CBaseChainParams::BSAFENET;
    return CBaseChainParams::MAIN;
}
