#pragma once

#include "GameObject.h"

BEGIN(Engine)
class CShader;
class CTexture;
class CRenderer;
class CVIBuffer_Rect;
END

BEGIN(Client)

class CUI final : public CGameObject
{
private:

	explicit CUI(LPDIRECT3DDEVICE9 pGraphic_Device);
	explicit CUI(const CUI& rhs);
	virtual ~CUI() = default;

public:

	virtual HRESULT NativeConstruct_Prototype()  override;
	virtual HRESULT NativeConstruct(void* pArg)  override;
	virtual _int    Tick(_double TimeDelta)		 override;
	virtual _int    Late_Tick(_double TimeDelta) override;
	virtual HRESULT Render()					 override;

private:

	CShader*		m_pShader	= nullptr;
	CTexture*       m_pTexture  = nullptr;
	CRenderer*      m_pRenderer = nullptr;
	CVIBuffer_Rect* m_pVIBuffer = nullptr;

private:

	_matrix m_WorldMatrix;
	_matrix m_ViewMatrix;
	_matrix	m_ProjMatrix;

	_float  m_fX, m_fY, m_fSizeX, m_fSizeY;

private:

	HRESULT Set_ConstTable();
	HRESULT Add_Components();

public:

	static  CUI*		 Create(LPDIRECT3DDEVICE9 pGraphic_Device);
	virtual CGameObject* Clone(void* pArg) override;
	virtual void		 Free() override;

};

END