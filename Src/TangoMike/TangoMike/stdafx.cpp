// stdafx.cpp : 표준 포함 파일만 들어 있는 소스 파일입니다.
// TangoMike.pch는 미리 컴파일된 헤더가 됩니다.
// stdafx.obj에는 미리 컴파일된 형식 정보가 포함됩니다.

#include "stdafx.h"

// TODO: 필요한 추가 헤더는
// 이 파일이 아닌 STDAFX.H에서 참조합니다.



//Device-Dependent Resources
ID3D10Device *m_pDevice = NULL;
IDXGISwapChain *m_pSwapChain = NULL;
ID3D10RasterizerState *m_pState = NULL;
ID3D10RenderTargetView *m_pRenderTargetView = NULL;
ID3D10Texture2D *m_pLoupeTexture = NULL;
ID2D1Bitmap *m_pLoupeBitmap = NULL;

ID2D1RenderTarget *m_pBackBufferRT = NULL;

ID2D1SolidColorBrush *m_pTextBrush = NULL;
ID2D1SolidColorBrush *m_pLoupeBrush = NULL;
IDWriteTextLayout* m_pTextLayout = NULL;


ID2D1PathGeometry *m_pPathGeometry = NULL;
ID2D1GeometrySink *m_pGeometrySink = NULL;
ID2D1GradientStopCollection *m_pGradientStops = NULL;
ID2D1LinearGradientBrush *m_pLGBrush = NULL;

PendingAcceptList pendingAcceptList;

IWICImagingFactory* g_pWICFactory = nullptr;

ID2D1LinearGradientBrush *linebrush_[FEEL_COUNT][WORK_COUNT];
ID2D1GradientStopCollection* linestops_ = nullptr;

ID2D1LinearGradientBrush *linebrush_background[FEEL_COUNT][WORK_COUNT];
ID2D1GradientStopCollection* lineStopCollection_ = nullptr;
ID2D1GradientStopCollection* lineStopCollection_background = nullptr;
ID2D1BitmapRenderTarget *pCompatibleRenderTarget = nullptr;
bool isFocus[FEEL_COUNT + WORK_COUNT] = { false, };
float distance(D2D1_POINT_2F* a, D2D1_POINT_2F* b)
{
	return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
}
bool didDrawBackground = false;
float g_opacity = 0.3f;
float g_lineThickness = 0.3f;


void LoadOpacityAndLineThickness()
{
	std::ifstream ifs("opacitySetting.txt");
	if (ifs.good())
	{
		ifs >> g_opacity >> g_lineThickness;
		ifs.close();
	}
}
void SaveOpacityAndLineThickness()
{
	std::ofstream ofs("opacitySetting.txt");
	if (ofs.good())
	{
		ofs << g_opacity << std::endl << g_lineThickness;
		ofs.close();
	}
}