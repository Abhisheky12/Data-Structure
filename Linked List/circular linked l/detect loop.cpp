class Solution {
  public:
    // Function to check if the linked list has a loop.
    bool check(vector<Node*>&visited,Node* curr){
          for(int i=0;i<visited.size();i++){
              if(visited[i]==curr){
                  return 1;
              }
          }
          return 0;
    }
    bool detectLoop(Node* head) {
        // your code here
        Node *curr=head;
        vector<Node*>visited;
        while(curr!=NULL){
            if(check(visited,curr)){
                return 1;
            }
            visited.push_back(curr);
            curr=curr->next;
        }
        return 0;
    }
};