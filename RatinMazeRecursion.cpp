#include <iostream>
#include <vector>
using namespace std;


void helper(vector<vector<int>> &mat,int row,int col,string path,vector <string> &ans,vector<vector<bool>> &vis){
	
	int n=mat.size();
	
	if(row<0||col<0||row>=n||col>=n||mat[row][col]==0||vis[row][col]==true){
		return;
	}
	
	if(row==n-1&&col==n-1){
		ans.push_back(path);
		return;
	}
	
	vis[row][col]=true;
	
	//down
	helper(mat,row+1,col,path+"D",ans,vis);
	//up
	helper(mat,row-1,col,path+"U",ans,vis);
	//left
	helper(mat,row,col-1,path+"L",ans,vis);
	//right
	helper(mat,row,col+1,path+"R",ans,vis);
	
	vis[row][col]=false;
}


vector <string> findPath(vector<vector<int>> &mat){
	int n=mat.size();
	vector<vector<bool>> vis(n,vector<bool>(n,false));
	
	vector <string> ans;
	string path = "";
	helper(mat,0,0,path,ans,vis);
	return ans;
	
	
}

int main(){
	
	vector<vector<int>> mat={{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};
	
	vector<string> ans=findPath(mat);
	for(string path : ans){
		cout<<path<<endl;
	}

}
