//
// Created by Hanxiang Ren on 2018-12-21.
//

#pragma once

#include "IApplication.hpp"

namespace My {
    class BaseApplication : public IApplication {
        virtual int Initialize();

        virtual void Finalize();

        virtual void Tick();

        virtual bool IsQuit();

    protected:
        // mark if the the application needs quitting in the main loop.
        bool m_bQuit;
    };
}



