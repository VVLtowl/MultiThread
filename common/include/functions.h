//!	@file		functions.h
//!	@brief		�}���`�X���b�h�ۑ�ŗ��p���鋤�ʊ֐��Q���`���܂��B
//! @note		Copyright (c) FromSoftware, Inc.

#ifndef __MultiThread_functions_h__
#define __MultiThread_functions_h__

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <windows.h>
#include <stdlib.h>
#include <assert.h>

//-----------------------------------------------------------------------------
// Implements
//-----------------------------------------------------------------------------
namespace ex02_MultiThread
{
	namespace common
	{
		/**************************************************************************//**
			@brief		���炢�܂킵�֐��ł��B
			@param		[in] x		x�l
			@param		[in] x		y�l
			@param		[in] x		z�l
			@return		�֐��̌���
		*//***************************************************************************/
		inline int Tarai( int x, int y, int z )
		{
			if( x <= y )
			{
				return y;
			}

			return Tarai(
						Tarai( x - 1, y, z ),
						Tarai( y - 1, z, x ),
						Tarai( z - 1, x, y )
						);
		}

		/**************************************************************************//**
			@brief		�w��͈͂ŗ�����Ԃ��܂��B
			@param		[in] min	���������ŏ��l
			@param		[in] max	���������ő�l
			@return		���[min,max]�̒l
		*//***************************************************************************/
		inline int Random( int min, int max )
		{
			//rand()�g�p�͈Ӑ}�I�B�ۑ�̌��ʂ��ێ����邽�ߎg�p���p������
			return min + (max - min) * rand() / RAND_MAX;
		}

		/**************************************************************************//**
			@brief		CPU���Ԃ��擾���܂��B
			@return		CPU����
		*//***************************************************************************/
		inline unsigned __int64 GetCPUCounter()
		{
			LARGE_INTEGER result;
			BOOL ret = ::QueryPerformanceCounter( &result );
			assert( ret );
			return result.QuadPart;
		}

		/**************************************************************************//**
			@brief		CPU���Ԃ�1�b�Ԃɐi�ޒl���擾���܂��B
			@return		CPU���Ԃ�1�b�Ԃɐi�ޒl
		*//***************************************************************************/
		inline unsigned __int64 GetCPUFrequency()
		{
			LARGE_INTEGER result;
			BOOL ret = ::QueryPerformanceFrequency( &result );
			assert( ret );
			return result.QuadPart;
		}
	}
}
#endif // __MultiThread_functions_h__
