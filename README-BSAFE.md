Bitcoin Core with BSafe.Network Modifications
=============================================

This branch of Bitcoin core includes support for creating
[BSafe.Network](https://bsafe.network/)'s Bitcoin blockchain
network `bsafenet` for its own testing purposes. Please refer to
[BSafe.Network site](https://bsafe.network/) on the motivation and
activities on the BSafe.Network.

This patch is currently maintained by Shigeya Suzuki <<shigeya@wide.ad.jp>>

Request for node installations & upgrades
-----------------------------------------

BSafe Network continues to further expand its research network and community activities. As such we would like to invite your participation in this milestone install & upgrade of BSafe node software.

At this moment, we call for two types of nodes, with different testing durations:

Node type 1 - Specific to Layer 2 competition (up to six months)
Node type 2 - For Layer 2 competition as well as other adjacent testing purposes (up to one year) 
Note: For the long-term experiment, we're currently designing an experimental system which will be capable of multi-blockchain/multi-software testing. This summer we'll reach out again for your participation, though as with all of our efforts we welcome your input at any time.

We urgently request your support with type 1 nodes.  Please respond if you can join us to expand our Layer 1 testing network (on the live Bitcoin network). 

Repository Location
-------------------

Current primary repository is located at
[https://github.com/keio-bcl/bitcoin](https://github.com/keio-bcl/bitcoin).
The code deployed to the network is maintained in
[`bsafe-deploy`](https://github.com/keio-bcl/bitcoin/tree/bsafe-deploy)
branch. Please clone and check out the branch accordingly, like this:

    git clone https://github.com/keio-bcl/bitcoin
    cd bitcoin
    git checkout bsafe-deploy

Baseline requirements
---------------------

Either virtual machine or bare-metal machines are fine. 

Recommended: 

- Processor 1 vCPU, dedicated better
- Memory: 1GB physical. You need 2GB virtual space when compiling it.
- Disk: 20GB  very minimum. 50GB recommended.
- Traffic: should be moderate, we assume it will be very similar to minimal web site traffic.
- Location: The machine should be located close to you, at least, in your country.

If you have any question regarding requirements, please ask. We currently run it on Linux, using Debian version 9.

Due to the nature of the experiment, we strongly suggest having one dedicated Virtual Machine for the purpose. 

Installation
------------

Please refer to [doc directory](doc) for general build
directions. While the maintainer believes it does not have any
platform dependency, we only tested on Debian 9 and MacOS X Mojave.
Please read [doc/build-unix.md](doc/build-unix.md) or
[doc/build-osx.md](doc/build-osx.md) on dependencies for build. There
is no specific build requirement for BSafe.Network patch.  If you
find any problem, please report to the maintainer.

At our site, we're building with the following steps:

    bash # maybe safer to do this
    ./autogen.sh
    ./configure
    make
    make install # optional


Running the daemon
------------------

To run with BSafeNetwork's network, use `-bsafenet` option to both
`bitcoind` and `bitcoin-cli` commands.


Update to the latest version
----------------------------

For updating the code, since we frequently rebase towards Bitcoin
Core's releases, we recommend the following steps:

    git checkout bsafe-deploy
    git fetch
    git reset --hard remotes/origin/bsafe-deploy
    # follow the same build steps

