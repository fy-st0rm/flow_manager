#define ROW 4
#define COL 4
#define KEY_CNT ROW * COL

typedef struct {
	char value;
	int lower, upper;
} Key;

static Key keys[] = {
	{
		.value = '1',
		.lower = 942,
		.upper = 945
	},
	{
		.value = '2',
		.lower = 910,
		.upper = 915
	},
	{
		.value = '3',
		.lower = 842,
		.upper = 846
	},
	{
		.value = 'A',
		.lower = 90,
		.upper = 500
	},
	{
		.value = '4',
		.lower = 947,
		.upper = 951
	},
	{
		.value = '5',
		.lower = 920,
		.upper = 927
	},
	{
		.value = '6',
		.lower = 865,
		.upper = 873
	},
	{
		.value = 'B',
		.lower = 520,
		.upper = 690
	},
	{
		.value = '7',
		.lower = 952,
		.upper = 956
	},
	{
		.value = '8',
		.lower = 930,
		.upper = 935
	},
	{
		.value = '9',
		.lower = 888,
		.upper = 893
	},
	{
		.value = 'C',
		.lower = 700,
		.upper = 780
	},
//	{
//		.value = '*',
//		.lower = 950,
//		.upper = 953
//	},
	{
		.value = '0',
		.lower = 937,
		.upper = 942
	},
//	{
//		.value = '#',
//		.lower = 943,
//		.upper = 945
//	},
//	{
//		.value = 'D',
//		.lower = 941,
//		.upper = 942
//	}
};


static char get_pressed_key() {
	int val = analogRead(A0);

	for (int i = 0; i < KEY_CNT; i++) {
		Key key = keys[i];
		if (key.lower <= val && val <= key.upper) {
			while (val < 1000) {
				val = analogRead(A0);
			}
			return key.value;
		}
	}
	return 0;
}

static int get_key_value() {
	int val = analogRead(A0);
	return val;
}
