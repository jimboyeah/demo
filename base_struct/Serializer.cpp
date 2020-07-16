/*

297. Serialize and Deserialize Binary Tree


Remaining time: 59 minutes, 59 seconds.
Serialize and Deserialize Binary Tree
Difficulty: Hard

Your Codec object will be instantiated and called as such:
Codec codec;
codec.deserialize(codec.serialize(root));

compile: cls && g++ -o Serializer Serializer.cpp && Serializer.exe
*/

#include <windows.h>
#include <iostream>
#include <string>
#include <deque>
#include <cstdio>

using namespace std;

/* in stdio.h
#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif
*/

/**
 * Definition for a binary tree node.
 */
typedef struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(     ) : val(0), left( NULL ), right( NULL) {}
    TreeNode(int x) : val(x), left( NULL ), right( NULL) {}
} TreeNode;

class Codec {
public:

    /*
	 * Encodes a tree to a single string.
	 * DATA FORMAT:
	 * Byte+Left+Right+Byte+Left+Right, 
	 * BYTE FORMAT:
	 * 0x01 has right, 0x02 has left, 0x3 both left & right
	 */
    string serialize(TreeNode* root) {
		if( root==NULL ) return string("");
		TreeNode &rt = *root;
		int msize = sizeof( ((TreeNode)0).val );
        char magic = 0x00;
		string s(msize+1, 'x');
		if( rt.left != NULL ){
			magic = magic | 0x02;
			s += serialize(rt.left);
		}
		if( rt.right!= NULL){
			magic = magic | 0x01;
			s += serialize(rt.right);
		}
		char * pd = (char *)s.data();
		char * pval = pd + 1;
		memcpy( pd,   &magic, 1);
		memcpy( pval, &rt.val, 4);
		return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0) return NULL;
		int index = 0;
		return deserialize(data, index);
    }

	TreeNode* deserialize( string &data, int &index ){
		int val, msize = 4; //sizeof( ((TreeNode)0).val );
		//int val = (int)(data[index+1]); // it's not working
		memcpy( &val, (void *)(data.data()+index+1), sizeof(int) );
		char magic = data[index];
		TreeNode *root = new TreeNode( val );
		TreeNode np = *root;
		index += msize + 1;
		if( magic & 0x02 ){
			root->left = deserialize( data, index );
		}
		if( magic & 0x01 ){
			root->right = deserialize( data, index );
		}
		return root;
	}

    // build tree.
    TreeNode * build(int i, int e, TreeNode * root) {
		TreeNode *r = new TreeNode(i);
		TreeNode *l = new TreeNode(i);
		root->left = l;
		root->right= r;
		if(i<e){
			build(i+1, e, l);
			build(i+1, e, r);
		}
		return root;
    }

	void print(TreeNode root){
		deque<TreeNode*> vn;
		int l=0, n=0, max_loop = 0xffff;

		vn.push_back(&root);

		while(--max_loop){
			n = vn.size();
			if( n<=0 ) break;
			while(n--){
				TreeNode &tn = *vn.front();
				vn.pop_front();
				if( tn.left ) cout << "<";
				cout << (char)tn.val << hex << "[" << tn.val << "]";
				if( tn.right ) cout << ">";
				cout << " ";
				if( tn.left!=NULL ) vn.push_back(tn.left);
				if( tn.right!=NULL ) vn.push_back(tn.right);
			}
			cout << endl;
		}
	}
};

void test(){
    char data[] = {'A','b',0x00,'C','D'};
    string a(data), b(data,sizeof(data)), c(5, 0x00);
    cout<< "string a: " << a << "\t" << a.size() <<endl;
    cout<< "string b: " << b << "\t" << b.size() <<endl;
	int a1st = (int)a.data();
	int a2nd = (int)a.data()+1;
	memcpy( (void*)c.data(), data, 5);
	cout << "string a+b: " <<  b+c << "\t" << (b+c).length() << endl;
    cout<< c << "\t" << c.size() << "\taddress: " << a1st << "\t" << a2nd <<endl;
    //cout<< (void*)a.data()<< "\t" << (void*)a.data()+1 <<endl;
}

int main(){
	TreeNode root('A');

	Codec cd;
	cd.build('x','z', &root);
	string s(cd.serialize(&root));

	cout << "Source TreeNode: \n";
	cd.print(root);
	cout << "Serialized: \n" << s << endl;
	cout << "And this deserialized: \n";
	root = *cd.deserialize(s);
	cd.print(root);

	TreeNode t1(1+'a');
	t1.left = new TreeNode(2+'a');
	t1.left->left = new TreeNode(255+256);
	string t1s( cd.serialize(&t1) );
	t1 = *cd.deserialize(t1s);
	cout << "Test t1:\n" << t1s << endl;
	cd.print(t1);

	TreeNode t2(1+'a');
	t2.left = new TreeNode(2+'a');
	t2.left->right = new TreeNode(3+'a');
	string t2s( cd.serialize(&t2) );
	t2 = *cd.deserialize(t2s);
	cout << "Test t2:\n" << t2s << endl;
	cd.print(t2);

	return 0;
}
