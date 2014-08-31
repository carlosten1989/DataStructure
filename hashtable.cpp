#define HASHTABLE_MAX_SIZE 1000

typedef struct hashnode {
	hashnode *next;
	const char* key;
	int val;
};

class hashtable {
private:
	int size;
	hashnode* p[HASHTABLE_MAX_SIZE];
	int hash_function(const char* key) {
		int ret = 0;
		return ret;
	}
public:
	hashtable() {
		size = 0;
		memset(p,0,sizeof(hashnode*)*HASHTABLE_MAX_SIZE);
	}

	void insert(const char* key, int value) {
		if(size >= HASHTABLE_MAX_SIZE) {
			//out of memory
		}
		int pos = hash_function(key) % HASHTABLE_MAX_SIZE;
		hashnode *pHead = p[pos];
		while(pHead) {
			if(strcmp(pHead->key,key) == 0) {
				//already exist
				return;
			}
			pHead = pHead->next;
		}
		hashnode *pNew = (hashnode*)malloc(sizeof(hashnode));
		memset(pNew,0,sizeof(hashnode));
		pNew->key = (char*)malloc(sizeof(char) * (strlen(key)+1));
		strcpy(pNew->key,key);
		pNew->val = value;
		pNew->next = p[pos];
		p[pos] = pNew;
		size ++;
	}

	void remove(const char* key) {
		int pos = hash_function(key) % HASHTABLE_MAX_SIZE;
		hashnode *pHead = p[pos];
		hashnode *pPre = NULL;
		while(pHead) {
			if(strcmp(pHead->key,key) == 0) {
				break;
			} else {
				pPre = pHead;
				pHead = pHead->next;
			}
		}
		if(pHead) {
			if(!pPre) {
				p[pos] = pHead->next;
			} else {
				pPre->next = pHead->next;
			}
			free(pHead->key);
			free(pHead);
		}
	}
};

