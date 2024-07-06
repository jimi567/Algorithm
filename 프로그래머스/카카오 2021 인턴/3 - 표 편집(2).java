import java.util.*;

class Solution {
    class Node{
        Node prev;
        Node next;
        boolean isDel;
    }
    
    public String solution(int n, int k, String[] cmd) {
        Node[] nodes = new Node[n+1];
        Stack<Node> st = new Stack();
        
        nodes[0] = new Node();
        for(int i=1;i<n;i++){
            Node prev = nodes[i-1];
            Node node = new Node();
            prev.next = node;
            node.prev = prev;
            nodes[i] = node;
        }
        
        Node now = nodes[k];
        for(String c : cmd){
            char op = c.charAt(0);
            if(op == 'U' || op == 'D'){
                int w = Integer.parseInt(c.substring(2)); //이거 때문에 틀림.. charAt(2)로 해서 w가 2자리인 경우를 고려 못함;
                if(op == 'U'){
                    for(int i=0;i<w;i++)  now = now.prev;
                }
                else{
                    for(int i=0;i<w;i++) now = now.next;
                }
            }
            else if(op == 'C'){
                now.isDel = true;
                st.push(now);
                Node prev = now.prev;
                Node next = now.next;
                if(prev == null && next == null ) continue; // 노드가 하나 남은 경우
                if(prev == null){ //첫번째 행
                    next.prev = null;
                    now = next;
                }
                else if(next == null){ //끝 행
                    prev.next = null;
                    now = prev;
                }
                else{
                    prev.next = next;
                    next.prev = prev;
                    now = next;
                }
            }
            else{
                Node backUp = st.pop();
                backUp.isDel = false;
                if(backUp.prev == null) backUp.next.prev = backUp;
                else if(backUp.next == null) backUp.prev.next = backUp;
                else{
                    backUp.prev.next = backUp;
                    backUp.next.prev = backUp;
                }
            }
        }
        
        StringBuilder answer = new StringBuilder();
        for(int i=0;i<n;i++){
            if(nodes[i].isDel) answer.append("X");
            else answer.append("O");
        }
        return answer.toString();
    }
}
