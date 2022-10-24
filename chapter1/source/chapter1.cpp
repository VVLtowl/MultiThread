//!	@file		chapter1.cpp
//!	@brief		�}���`�X���b�h�ۑ�@��1��
//! @note		Copyright (c) FromSoftware, Inc.

//-----------------------------------------------------------------------------
// File Dependencies
//-----------------------------------------------------------------------------

#include <stdio.h>
#include <functions.h>
#include <crtdbg.h>

#include <thread>

//-----------------------------------------------------------------------------
// Macro Definitions
//-----------------------------------------------------------------------------

#define N		100000
#define	MIN		1
#define	MAX		13
#define RESULT	833197		// ���̌v�Z�͂��̒l�ɂȂ�܂�

//-----------------------------------------------------------------------------
// Using Namespace
//-----------------------------------------------------------------------------
using namespace ex02_MultiThread::common;

//-----------------------------------------------------------------------------
// Implements
//-----------------------------------------------------------------------------
namespace ex02_MultiThread
{
	namespace chapter1
	{
		/*********************************************************
		* @brief		�񐔂��ݒ�ł����Ɗ֐�
		* @param		[in]times: ��
		* @param		[out]sum: �l���i�[����ϐ�
		********************************************************/
		void Work(int times,int* sum)
		{
			for (int i = 0; i < times; i++)
			{
				int x = Random(MIN, MAX);
				int y = Random(MIN, MAX);
				int z = Random(MIN, MAX);

				*sum += Tarai(x, y, z);
			}
		}

		/**************************************************************************//**
			@brief		��Ƃ��s���܂��B
			@return		��Ƃ̌���
			@todo		���̊֐����������A�������ʂ���荂���ɕԂ���悤�ɂ��Ă��������B
		*//***************************************************************************/
		int DoWork()
		{

#if 0
			int sum = 0;

			for( int i = 0; i < N; i++ )
			{
				int x = Random( MIN, MAX );
				int y = Random( MIN, MAX );
				int z = Random( MIN, MAX );

				sum += Tarai( x, y, z );
			}
			return sum;
#endif
			int sum1 = 0;
			int sum2 = 0;

			std::thread thread1(Work, N / 2, &sum1);
			std::thread thread2(Work, N / 2, &sum2);

			thread1.join();
			thread2.join();

			return sum1 + sum2;
		}
	}
}
/**************************************************************************//**
	@brief		�v���O�����J�n�֐��ł��B
*//***************************************************************************/
void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	unsigned __int64 startTime = GetCPUCounter();
	int result = ex02_MultiThread::chapter1::DoWork();
	unsigned __int64 endTime = GetCPUCounter();

	printf( "time : %f\n", (double)(endTime - startTime) / (double)GetCPUFrequency() );
	printf( "result : %d\n", result );
}