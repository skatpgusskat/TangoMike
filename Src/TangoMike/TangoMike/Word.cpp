#include "stdafx.h"
#include "Word.h"

Word::Word()
	: textAlignment_(DWRITE_TEXT_ALIGNMENT_LEADING),//DWRITE_TEXT_ALIGNMENT_LEADING
	paragraphAlignment_(DWRITE_PARAGRAPH_ALIGNMENT_NEAR),
	contents_(L""),
	fontName_(L"Calibri"),
	fontSize_(20.f),
	fontSizeAnimation_(&fontSize_),
	fontColorAnimation_(&fontColor_)
{
	position_ = D2D1::Point2F();
}
Word::Word(std::wstring contents, D2D_POINT_2F position)
	: textAlignment_(DWRITE_TEXT_ALIGNMENT_LEADING),//DWRITE_TEXT_ALIGNMENT_LEADING
	paragraphAlignment_(DWRITE_PARAGRAPH_ALIGNMENT_NEAR),
	contents_(contents),
	fontName_(L"Calibri"),
	fontSize_(20.f),
	fontSizeAnimation_(&fontSize_),
	fontColorAnimation_(&fontColor_)
{
	position_ = position;
}


Word::~Word()
{
}


void Word::Render()
{
	Component::Render();

	HRESULT hr = S_OK;


	if (hr == S_OK){
		hr = m_pDWriteFactory->CreateTextFormat(
			fontName_,
			NULL,
			DWRITE_FONT_WEIGHT_NORMAL,
			DWRITE_FONT_STYLE_NORMAL,
			DWRITE_FONT_STRETCH_NORMAL,
			fontSize_,
			L"", // locale
			&m_pTextFormat
			);
	}
	if (hr == S_OK){
		hr = m_pTextFormat->SetTextAlignment(textAlignment_);
	}

	if (hr == S_OK){
		m_pBackBufferRT->BeginDraw();

		m_pBackBufferRT->SetTransform(matrix_);

		m_pBackBufferRT->CreateSolidColorBrush(
			fontColor_, &m_pTextBrush);


		m_pBackBufferRT->DrawText(
			contents_.c_str(),
			contents_.length(),
			m_pTextFormat,
			D2D1::RectF(0.f, 0.f, maxWidthAndHeight.x, maxWidthAndHeight.y),
			m_pTextBrush,
			D2D1_DRAW_TEXT_OPTIONS_NONE
			);
	}
	hr = m_pBackBufferRT->EndDraw();
	SafeRelease(&m_pTextBrush);
	SafeRelease(&m_pTextFormat);


}

void Word::Update(float dTime)
{
	Component::Update(dTime);
	fontColorAnimation_.OnAnimate(dTime);
}

void Word::DoFontSizeAnimate(float fontSize, float duration)
{
	fontSizeAnimation_.DoAnimate(fontSize, duration);
}

void Word::DoFontColorAnimate(D2D_COLOR_F color, float duration)
{
	fontColorAnimation_.DoAnimate(color, duration);
}
