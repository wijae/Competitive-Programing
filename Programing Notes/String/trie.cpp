const int M = 26;
struct TrieNode{
	TrieNode *child[M];
	bool end;

	TrieNode(){
		int i;
		for(i=0 ;i<M; i++)
			child[i] = NULL;

		end = false;
	}

	bool search(char a){
		return child[a-'a']!=NULL;
	}

	TrieNode* append(char a){
		a = a - 'a';
		if(!child[a])
			child[a] = new TrieNode();
		
		return child[a];
	}
};

struct Trie{
	TrieNode* root;

	Trie(){
		root = TrieNode();
	}

	bool search(string s){
		TrieNode* n = root;
		for(int i=0; i<s.size(); i++){
			if(n->search(s[i]))
				n = n->append(s[i]);
			else
				return false;
		}

		return n->end;
	}

	void append(string s){
		TrieNode* n = root;
		for(int i=0; i<s.size(); i++)
			n = n->append(a[j][i]);

		n->end = true;
	}
}