#include "ProcessStateBase.hpp"
#include <cstdio>


StateError ProcessStateBase::enter(StateContext& context) {

    return onEnter(context);
}

StateResult ProcessStateBase::update(StateContext& context) {

    return onUpdate(context);
}

StateError ProcessStateBase::exit(StateContext& context) {

    return onExit(context);
}