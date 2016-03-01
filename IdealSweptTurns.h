#ifndef IDEALSWEPTTURNS_H
#define IDEALSWEPTTURNS_H

#include "conf.h"

enum SweptTurnType {
  kLeftTurn45, kLeftTurn90, kLeftTurn135, kLeftTurn180,
  kRightTurn45, kRightTurn90, kRightTurn135, kRightTurn180
};

class IdealSweptTurns {
 private:
  float tangential_velocity;
  float turn_angle;
  float acceleration_duration;
  float const_velocity_duration;
  float turn_duration;
  float time_step;
  float frict_force;
  float inside_trigs;
  float mm_per_radian;
  
  float getAngleAtTime(float t, bool build_time_table);
  float getVelocityAtTime(float t);
  float getTurnOffset(float angle);
  
 public:
  IdealSweptTurns(float temp_tangential_velocity, float temp_turn_angle, float temp_time_step);
  float getOffsetAtMicros(unsigned long input_time);
  unsigned long getTotalTime();
  int getTotalTurnSteps();
  float offset_table[500];
};

#endif
