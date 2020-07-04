//
// Created by Adam Keim on 6/30/20.
//


#ifndef TEENSYTRACER_ARDUINOMACROFIX_H
#define TEENSYTRACER_ARDUINOMACROFIX_H


#pragma once

/**
 * @file
 * @brief   Fixes for problematic macros defined by the Arduino Core.
 *
 * The Arduino Core defines some macros for abs, min, max, etc. that cause
 * compilation problems when including the C++ standard library headers that
 * define these names as functions (as they should be defined).
 */

#ifdef ARDUINO

#include <Arduino.h>

#ifdef abs
#undef abs
#endif

#ifdef swap
#undef swap
#endif

#ifdef min
#undef min
#endif

#ifdef max
#undef max
#endif

#ifdef round
#undef round
#endif

#ifdef B1
#undef B1
#endif

#endif


#endif //TEENSYTRACER_ARDUINOMACROFIX_H
