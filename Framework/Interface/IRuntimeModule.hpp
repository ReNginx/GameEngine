//
// Created by Hanxiang Ren on 2018-12-21.
//

#pragma once

#include "Interface.hpp"

namespace My {
    class IRuntimeModule {
    public:
        virtual ~IRuntimeModule() {};

        virtual int Initialize() = 0;

        virtual void Finalize() = 0;

        virtual void Tick() = 0;
    };
}