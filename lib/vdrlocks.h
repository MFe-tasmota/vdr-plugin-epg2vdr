/*
 * vdrlocks.h
 *
 * See the README file for copyright information and how to reach the author.
 *
 */

#ifndef __VDRLOCKS_H
#  define __VDRLOCKS_H

#  ifdef VDR_PLUGIN

#  include <vdr/config.h>
#  include <vdr/tools.h>


#if defined (APIVERSNUM) && (APIVERSNUM >= 20301)
#  define GET_TIMERS_READ(name) USE_LIST_LOCK_READ(Timers);  \
   const cTimers* name = Timers;
#else
#  define GET_TIMERS_READ cTimers* timers = &Timers;
#endif

#if defined (APIVERSNUM) && (APIVERSNUM >= 20301)
#  define GET_TIMERS_WRITE(name) USE_LIST_LOCK_WRITE(Timers);   \
   cTimers* name = Timers;
#else
#  define GET_TIMERS_READ cTimers* timers = &Timers;
#endif

//***************************************************************************
#  endif // VDR_PLUGIN

#endif //___VDRLOCKS_H