//
// Created by Madalena Ye on 01/11/2022.
//

#ifndef SCHEDULE_BINARYSEARCHTREE_H
#define SCHEDULE_BINARYSEARCHTREE_H
#include "Student.h"
#include <vector>
struct TreeNode{
    TreeNode* left;
    TreeNode* right;
    Student value;
};

TreeNode* buildTree(vector<Student>students,int left, int right){
    if(left>right) return nullptr;
    int mid= left+(right-left)/2;
    TreeNode* node= new TreeNode;
    node->value=students[mid];
    node->left= buildTree(students,left,mid-1);
    node->right= buildTree(students,mid+1,right);
    return node;
}

TreeNode* sortedVectorToBST(vector<Student> students){
    if(students.size()==0) return nullptr;
    return buildTree(students,0,(int)students.size()-1);
}

TreeNode* findInBST(TreeNode* node,int val){
    if(node== nullptr)return nullptr;
    if(val==node->value.get_studentCode()){
        return node;
    }
    if(val>node->value.get_studentCode()) return findInBST(node->right,val);
    if(val<node->value.get_studentCode()) return findInBST(node->left,val);

    return node;
}
TreeNode* binarySearchTreeStudents(set<Student> students){
    vector<Student> v;
    for(auto it: students){v.push_back(it);}
    TreeNode* studentBST= sortedVectorToBST(v);
    return studentBST;
}

#endif //SCHEDULE_BINARYSEARCHTREE_H
