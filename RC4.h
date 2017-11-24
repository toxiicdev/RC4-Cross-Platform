#ifndef ARC4_H_
#define ARC4_H_

class RC4
{
public:
	static void encrypt(unsigned char* input, int input_length, unsigned char* output, unsigned char* key, int key_length)
	{
		int x, y, j = 0;

		memcpy(output, input, input_length);

		unsigned char box[256];
		for (int i = 0; i < 256; i++)
			box[i] = i;

		for (int i = 0; i < 256; i++)
		{
			j = (key[i % key_length] + box[i] + j) % 256;
			x = box[i];
			box[i] = box[j];
			box[j] = x;
		}

		for (int i = 0; i < input_length; i++)
		{
			y = (i + 1) % 256;
			j = (box[y] + j) % 256;
			x = box[y];
			box[y] = box[j];
			box[j] = x;

			output[i] ^= box[(box[y] + box[j]) % 256];
		}
	}
};


#endif
