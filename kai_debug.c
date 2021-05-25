/*
    Debug for K Audio Interface
    Copyright (C) 2021 by KO Myung-Hun <komh@chollian.net>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public
    License along with this library; if not, write to the Free
    Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>

#include "kai_internal.h"
#include "kai_spinlock.h"
#include "kai_debug.h"

static SPINLOCK m_lock = SPINLOCK_INIT;

void _kaiDprintf( const char *format, ... )
{
    va_list args;
    char msg[ 256 ];

    if( !_kaiIsDebugMode())
        return;

    spinLock( &m_lock );

    va_start( args, format );
#ifndef __IBMC__
    vsnprintf( msg, sizeof( msg ), format, args );
#else
    vsprintf( msg, format, args );
#endif
    va_end( args );

    fprintf( stderr, "%08ld %s\n", clock() * 1000 / CLOCKS_PER_SEC, msg );

    spinUnlock( &m_lock );
}
