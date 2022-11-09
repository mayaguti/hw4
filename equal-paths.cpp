#include "equal-paths.h"
#include <algorithm>
using namespace std;


// You may add any prototypes of helper functions here
int calculateHeightIfEqual(Node * root){
	if (root == nullptr) return 0;
	int rHeight = calculateHeightIfEqual(root->right);
	int lHeight = calculateHeightIfEqual(root->left);

	if (lHeight == -1 || rHeight == -1){
		return -1;
	}
	if(rHeight == 0){
		return lHeight + 1;
	}
	if (lHeight == 0){
		return rHeight + 1;
	}
	if(std::abs(rHeight - lHeight) == 0){
		return std::max(rHeight, lHeight) + 1;
	}
	else{
		return -1;
	}
}

bool equalPaths(Node * root)
{
    // Add your code below
	return calculateHeightIfEqual(root) != -1;
}

