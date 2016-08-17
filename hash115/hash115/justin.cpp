

1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
43
44
45
46
47
48
49
50
51
52
53
54
55
56
57
58
59
60
61
62
63
64
65
66
67
68
69
70
71
72
73
74
75
76
77
78
79
80
81
82
83
84
85
86
87
88
89
90
91
92
93
94
95
96
97
98
99
100
101
102
103
104
105
106
107
108
109
110
111
112
113
114
115
116
117
118
119
120
121
122
123
124
125
126
127
128
129
130
131
132
133
134
135
136
137
138
139
140
141
142
143
144
145
146
147
148
149
150
151
152
153
154
155
156
157
158
159
160
161
162
163
164
165
166
167
168
169
170
171
172
173
174
175
176
177
178
179
180
181
#include <iostream>
#include <cstdlib>

using namespace std;

const int HASHSIZE = 4001;

class HashNode {
private:
	char* key;
	int value;

public:
	HashNode(char* key, int value){
		this->key = key;
		this->value = value;
	}

	HashNode(){
		this->key = NULL;
		this->value = NULL;
	}

	void setKey(char* key){
		this->key = key;
	}

	char* getKey(){
		return key;
	}


	int getValue(){
		return value;
	}

	void incrementValue(){
		value += 1;
	}
};

class HashTable {

private:
	HashNode **table;

	int sfold(char* key) {
		unsigned int *lkey = (unsigned int *)key;
		int intlength = strlen(key) / 4;
		unsigned int sum = 0;
		for (int i = 0; i<intlength; i++)
			sum += lkey[i];
		// Now deal with the extra chars at the end
		int extra = strlen(key) - intlength * 4;
		char temp[4];
		lkey = (unsigned int *)temp;
		lkey[0] = 0;
		for (int i = 0; i<extra; i++)
			temp[i] = key[intlength * 4 + i];
		sum += lkey[0];
		return sum % HASHSIZE;
	}

	int count;

	int current;

	char* EMPTYKEY;

public:

	int access;

	HashTable(){
		table = new HashNode*[HASHSIZE];
		char* EMPTYKEY = "000";
		count = 0;
		current = 0;
		for (int i = 0; i < HASHSIZE; i++){
			table[i] = nullptr;
		}
	}

	~HashTable() {
		for (int i = 0; i < HASHSIZE; i++)
			delete table[i];
		delete[] table;
	}


	int size(){
		return count;
	}

	void hashInsert(char* k) {
		int home;
		int pos = home = sfold(k);
		for (int i = 1; table[pos] != NULL; i++) {
			pos = (home + i) % HASHSIZE;
		}
		count++;
		table[pos] = new HashNode(k, 1);
	}

	int hashSearch(char* k){
		int home;
		int pos = home = sfold(k);

		for (int i = 1; (table[pos] != NULL && k != table[pos]->getKey()); i++) {
			access += 2;
			pos = (home + i) % HASHSIZE;
		}
		if (table[pos] != NULL && k != table[pos]->getKey()){
			access++;
			return pos;
		}
		else {
			return -1;
		}
	}

	void update(char* k){
		int pos = hashSearch(k);
		if (pos != -1){
			access++;
			table[pos]->incrementValue();
		}
		else{
			hashInsert(k);
		}
	}

	void reset(){
		current = -1;
	}
	void setCurrent(int i){
		current = i;
	}

	int getCurrent(){
		return current;
	}


	void traverseHashTable(){
		reset();

		for (int i = getCurrent(); i < HASHSIZE; i++){
			char* key = " WRONG ";
			int val = -1;
			next(key, val);
			std::cout << key << val;
		}
	}

	void next(char* &key, int &val){

		for (int i = getCurrent(); i < HASHSIZE; i++){
			if (table[i] != NULL){
				key = table[i]->getKey();
				val = table[i]->getValue();
				setCurrent(i + 1);
				return;
			}

		}
	}

};

int main(){

	HashTable HT;

	HT.update("C");

	HT.traverseHashTable();


	return 0;
}