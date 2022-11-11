#ifndef MODEHANDLEREDITION_H
#define MODEHANDLEREDITION_H


class ModeHandlerEdition
{
public:


private:
    enum class Mode{
        idle, object_selected
    };

    Mode mode_ = Mode::idle;
};

#endif // MODEHANDLEREDITION_H
