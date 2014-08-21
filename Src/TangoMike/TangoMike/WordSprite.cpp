#include "stdafx.h"
#include "WordSprite.h"



WordSprite::WordSprite(Object& object)
{
	float maxWidth = max(object.GetWidth(), object.GetEnglishWidth());

	koreanWord_.SetContents(object.GetName());
	koreanWord_.SetFontSize(KOREAN_IDLE_FONT_SIZE);
	koreanWord_.SetPosition(D2D1::Point2F(0.f, 0.f));
	koreanWord_.SetMaxWidthAndHeight(D2D1::Point2F(maxWidth, KOREAN_IDLE_FONT_SIZE));
	koreanSize_ = D2D1::Point2F(object.GetWidth(), KOREAN_IDLE_FONT_SIZE);

	englishWord_.SetContents(object.GetEnglishName());
	englishWord_.SetFontSize(ENGLISH_IDLE_FONT_SIZE);
	englishWord_.SetPosition(D2D1::Point2F(0.f, KOREAN_IDLE_FONT_SIZE));
	englishWord_.SetMaxWidthAndHeight(D2D1::Point2F(maxWidth, ENGLISH_IDLE_FONT_SIZE));
	englishSize_ = D2D1::Point2F(object.GetEnglishWidth(), ENGLISH_IDLE_FONT_SIZE);


	AddChild(&koreanWord_);
	AddChild(&englishWord_);
}


WordSprite::~WordSprite()
{
}

void WordSprite::Render()
{
	Component::Render();
}

void WordSprite::Update(float dTime)
{
	Component::Update(dTime);
}