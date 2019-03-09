/* I tried really hard for solving the question. Saw into various resources. I inderstood
   the theory but really felt difficult to implement it as this was the first time I am using
   binary tree.
   
   The fact that each 2 digit integer occupies 2 indexes in the array made the problem more challenging.*/
   
 //  This is the function i could think of //
 int find_ind(string str, int s, int e)                  //constructing from lower level nodes
{ 
    if (s > e) 
        return -1;
    stack<char> st; 
  
    for (int i = s; i <= e; i++) { 
  
        if (str[i] == '[') 
            st.push(str[i]); 
        else if (str[i] == ']') { 
            if (st.top() == '[') { 
                st.pop(); 
                if (st.empty()) 
                    return i; 
            } 
        } 
    } 
    return -1; 
} 
  


node* parenthetical_to_tree(string str, int s, int e)        // making the tree
{ 
    if (s > e) 
        return NULL; 
  
    node* root = new_node(str[s] - '0'); 
    int index = -1; 
   
    if (s + 1 <= e && str[s + 1] == '[') 
        index = find_ind(str, s + 1, e); 
  
    if (index != -1) { 
   
        root->left = parenthetical_to_tree(str, s + 2, index - 1);
        root->right = parenthetical_to_tree(str, index + 1, e - 1); 
    } 
    return root; 
}
