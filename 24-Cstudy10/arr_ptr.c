void main()
{
	int Arr[5];

	Arr[0] = 0x00;
	Arr[1] = 0x11;
	Arr[2] = 0x22;
	Arr[3] = 0x33;
	Arr[4] = 0x44;

	*(Arr+0) = 0x55;
	*(Arr+1) = 0x66;
	*(Arr+2) = 0x77;
	*(Arr+3) = 0x88;
	*(Arr+4) = 0x99;
}

