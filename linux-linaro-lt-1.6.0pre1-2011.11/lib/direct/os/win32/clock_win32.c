/*
   (c) Copyright 2001-2008  The world wide DirectFB Open Source Community (directfb.org)
   (c) Copyright 2000-2004  Convergence (integrated media) GmbH

   All rights reserved.

   Written by Denis Oliver Kropp <dok@directfb.org>,
              Andreas Hundt <andi@fischlustig.de>,
              Sven Neumann <neo@directfb.org>,
              Ville Syrjälä <syrjala@sci.fi> and
              Claudio Ciccani <klan@users.sf.net>.

   This library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2 of the License, or (at your option) any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with this library; if not, write to the
   Free Software Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.
*/

#include <config.h>

#include <sys/timeb.h>

#include <direct/clock.h>
#include <direct/messages.h>
#include <direct/util.h>

/**********************************************************************************************************************/

static long long session_clock_offset;

/**********************************************************************************************************************/

__no_instrument_function__
long long
direct_clock_get_time( DirectClockType type )
{
     struct _timeb timebuffer;

     _ftime64_s( &timebuffer );

     return timebuffer.time * 1000000LL + timebuffer.millitm * 1000LL;
}

DirectResult
direct_clock_set_time( DirectClockType type,
                       long long       micros )
{
     return DR_UNIMPLEMENTED;
}

long long
direct_clock_resolution( DirectClockType type )
{
     return 1LL;
}

