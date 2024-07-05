//1회차 - X
import java.util.*;

class Solution {
    
    class Row{
        int pos;
        boolean isDeleted;
        
        Row(int pos,boolean isDeleted){
            this.pos = pos;
            isDeleted = isDeleted;
        }
        
        void del(){
            isDeleted = true;
        }
        
        void backUp(){
            isDeleted = false;
        }
    }
    
    public String solution(int n, int k, String[] cmd) {
        List<Row> list = new ArrayList<>();
        Stack<Row> st = new Stack<>();
        
        for(int i=0;i<n;i++){
            list.add(new Row(i,false));
        }
        int size = list.size();
        for(int i=0;i<cmd.length;i++){
            System.out.println(k);
            char op = cmd[i].charAt(0);
            if(op == 'U' || op == 'D'){
                int w = cmd[i].charAt(2) - '0';
                int moveCnt = 0;
                if(op == 'U') {
                    while(w > 0){
                        moveCnt++;
                        if(list.get(k-moveCnt).isDeleted) continue;
                        w--;
                    }
                    k -= moveCnt;
                }
                else {
                      while(w > 0){
                        moveCnt++;
                        if(list.get(k+moveCnt).isDeleted) continue;
                        w--;
                    }
                    k += moveCnt;
                }
            }
            else if(op == 'C'){
                Row removed = list.get(k);
                removed.del();
                st.push(removed);
                size--;
                if(k  == size-1) k--; //K가 끝 위치였으면 윗 행 선택
            }
            else{
                Row row = st.pop();
                row.backUp();
                size++;
            }
        }
        
        StringBuilder answer = new StringBuilder();
        for(int i=0;i<n;i++){
            if(list.get(i).isDeleted) answer.append("X");
            else answer.append("O");
        }
        
        return answer.toString();
    }
}
