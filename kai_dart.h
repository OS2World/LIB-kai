/*
    Direct Audio Interface for K Audio Interface
    Copyright (C) 2007-2015 by KO Myung-Hun <komh@chollian.net>
    Copyright (C) by Alex Strelnikov
    Copyright (C) 1998 by Andrew Zabolotny <bit@eltech.ru>

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

#ifndef __KAI_DART_H__
#define __KAI_DART_H__

#include <os2.h>

#ifdef __cplusplus
extern "C" {
#endif

APIRET APIENTRY _kaiDartInit( PKAIAPIS pkai, PKAICAPS pkc );

#ifdef __cplusplus
}
#endif

#endif
