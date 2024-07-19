#pragma once

class IService {
    public:
        virtual bool init() = 0;
        virtual void run() = 0;
        virtual void kill() = 0;

    protected:
    private:
};
