#pragma once

#include "Base.h"

BEGIN(Engine)

class CTimer final : public CBase
{
private:

	explicit CTimer();
	virtual ~CTimer() = default;

public:

	HRESULT NativeConstruct();
	_float  Update_Timer();

private:

	_float		  m_fDeltaTime = 0.f;
	LARGE_INTEGER m_tCpuTick   = {};
	LARGE_INTEGER m_tBegin     = {};
	LARGE_INTEGER m_tEnd       = {};

public:

	static CTimer* Create();
	virtual void   Free() override;

};

END