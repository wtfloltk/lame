/**
 *
 * Lame ACM wrapper, encode/decode MP3 based RIFF/AVI files in MS Windows
 *
 *  Copyright (c) 2002 Steve Lhomme <steve.lhomme at free.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */
 
/*!
	\author Steve Lhomme
	\version \$Id: ACMStream.h,v 1.5 2006/12/25 21:37:34 robert Exp $
*/

#if !defined(_ACMSTREAM_H__INCLUDED_)
#define _ACMSTREAM_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <mmreg.h>
#include <msacm.h>
#include <msacmdrv.h>

#include "ADbg/ADbg.h"

#include "AEncodeProperties.h"


typedef enum vbr_mode_e vbr_mode;
typedef struct lame_global_struct lame_global_flags;


class ACMStream
{
public:
	ACMStream( );
	virtual ~ACMStream( );

	static ACMStream * Create();
	static const bool Erase(const ACMStream * a_ACMStream);

	bool init(const long double nSamplesPerSec, const long double nOutputSamplesPerSec, const long double nChannels, const long double nAvgBytesPerSec, const vbr_mode mode);
	bool open(const AEncodeProperties & the_Properties);
	bool close(LPBYTE pOutputBuffer, DWORD *pOutputSize);

	DWORD GetOutputSizeForInput(const DWORD the_SrcLength) const;
	bool  ConvertBuffer(LPACMDRVSTREAMHEADER a_StreamHeader);

	static long double GetOutputSampleRate(long double samples_per_sec, long double bitrate, long double channels);

protected:
	lame_global_flags * gfp;

	ADbg * my_debug;
	long double my_SamplesPerSec;
	long double my_Channels;
	long double my_AvgBytesPerSec;
	long double my_OutBytesPerSec;
	vbr_mode my_VBRMode;
	DWORD  my_SamplesPerBlock;

long double m_WorkingBufferUseSize;
	char m_WorkingBuffer[2304*2]; // should be at least twice my_SamplesPerBlock

inline long double GetBytesPerBlock(DWORD bytes_per_sec, DWORD samples_per_sec, long double BlockAlign) const;

};

#endif // !defined(_ACMSTREAM_H__INCLUDED_)

