class RC4
    {
        public static byte[] rc4(byte[] input, byte[] key)
        {
            byte[] encrypted = new byte[input.Length];
            int x, y, j = 0;
            int[] box = new int[256];
 
            for (int i = 0; i < 256; i++) box[i] = i;
 
            for (int i = 0; i < 256; i++)
            {
                j = (key[i % key.Length] + box[i] + j) % 256;
                x = box[i];
                box[i] = box[j];
                box[j] = x;
            }
 
            for (int i = 0; i < input.Length; i++)
            {
                y = (i + 1) % 256;
                j = (box[y] + j) % 256;
                x = box[y];
                box[y] = box[j];
                box[j] = x;

                encrypted[i] = (byte)(input[i] ^ box[(box[y] + box[j]) % 256]);
            }

            return encrypted;
        }
    }
