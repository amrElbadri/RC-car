void forward()
{
	SET_BIT(PORTA,mRP);
	SET_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void backward()
{
	CLR_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	SET_BIT(PORTA,mLP);
}
void Right()
{
	SET_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	SET_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}
void stop()
{
	CLR_BIT(PORTA,mRP);
	CLR_BIT(PORTA,mRN);
	CLR_BIT(PORTA,mLN);
	CLR_BIT(PORTA,mLP);
}