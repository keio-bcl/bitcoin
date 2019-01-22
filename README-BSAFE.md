Bitcoin Core with BSafe.Network Modifcations
============================================

This branch of Bitcoin core includes support for creating
[BSafe.Network](https://bsafe.network/)'s Bitcoin blockchain
network `bsafenet` for its own testing purposes. Please refer to
[BSafe.Network site](https://bsafe.network/) on the motivation and
activities on the BSafe.Network.

This patch is currently maintained by Shigeya Suzuki <<shigeya@wide.ad.jp>>


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

