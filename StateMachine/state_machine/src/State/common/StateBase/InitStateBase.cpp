#include "InitStateBase.hpp"
#include <cstdio>

StateResult InitStateBase::update(StateContext& context) {

    return onUpdate(context);
}

StateError InitStateBase::enter(StateContext& context) {


    return onEnter(context);
}

StateError InitStateBase::exit(StateContext& context) {

    return onExit(context);
}