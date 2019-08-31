//
// Copyright (c) 2015-2018 The leisurecoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.
//

#ifndef leisurecoin_LIGHTzlsrTHREAD_H
#define leisurecoin_LIGHTzlsrTHREAD_H

#include <atomic>
#include "genwit.h"
#include "zlsr/accumulators.h"
#include "concurrentqueue.h"
#include "chainparams.h"
#include <boost/function.hpp>
#include <boost/thread.hpp>

extern CChain chainActive;
// Max amount of computation for a single request
const int COMP_MAX_AMOUNT = 60 * 24 * 60;


/****** Thread ********/

class CLightWorker{

private:

    concurrentqueue<CGenWit> requestsQueue;
    std::atomic<bool> isWorkerRunning;
    boost::thread threadIns;

public:

    CLightWorker() {
        isWorkerRunning = false;
    }

    enum ERROR_CODES {
        NOT_ENOUGH_MINTS = 0,
        NON_DETERMINED = 1
    };

    bool addWitWork(CGenWit wit) {
        if (!isWorkerRunning) {
            LogPrintf("%s not running trying to add wit work \n", "leisurecoin-light-thread");
            return false;
        }
        requestsQueue.push(wit);
        return true;
    }

    void StartLightzlsrThread(boost::thread_group& threadGroup) {
        LogPrintf("%s thread start\n", "leisurecoin-light-thread");
        threadIns = boost::thread(boost::bind(&CLightWorker::ThreadLightzlsrSimplified, this));
    }

    void StopLightzlsrThread() {
        threadIns.interrupt();
        LogPrintf("%s thread interrupted\n", "leisurecoin-light-thread");
    }

private:

    void ThreadLightzlsrSimplified();

    void rejectWork(CGenWit& wit, int blockHeight, uint32_t errorNumber);

};

#endif //leisurecoin_LIGHTzlsrTHREAD_H
