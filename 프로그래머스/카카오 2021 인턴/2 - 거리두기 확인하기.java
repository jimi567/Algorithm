import java.util.*;

class Solution {
    
    private String[] place;
    
    public int[] solution(String[][] places) {
        int[] answer = new int[5];
        for(int i=0;i<places.length; i++){
            this.place = places[i];
            answer[i] = getAns(places[i]);
        }
        
        return answer;
    }
    
    private int getAns(String[] place){
        
        for(int i=0;i<place.length;i++){
            for(int j=0;j<place[i].length();j++){
                if(place[i].charAt(j) != 'P') continue;
                if(!checkLeft(i,j)) return 0;
                if(!checkRight(i,j)) return 0;
                if(!checkUp(i,j)) return 0;
                if(!checkDown(i,j)) return 0;
                if(!checkRightUp(i,j)) return 0;
                if(!checkLeftUp(i,j)) return 0;
                if(!checkRightDown(i,j)) return 0;
                if(!checkLeftDown(i,j)) return 0;
            }
        }
        return 1;
    }
    
    private boolean checkLeft(int r,int c){
        int[] dx = {-1,-2};
        int[] dy = {0,0};
        
        if(isP(r + dx[0], c + dy[0])) return false;
        if(isP(r + dx[1], c+ dy[1]) && !isX(r + dx[0],c+ dy[0])) return false;
        
        return true;
    }
    
    private boolean checkRight(int r,int c){
        int[] dx = {1,2};
        int[] dy = {0,0};
        
        if(isP(r + dx[0], c + dy[0])) return false;
        if(isP(r + dx[1], c+ dy[1]) && !isX(r + dx[0],c+ dy[0])) return false;
        
        return true;
    }
    
    private boolean checkUp(int r, int c){
        int[] dx = {0,0};
        int[] dy = {-1,-2};
        
        if(isP(r + dx[0], c + dy[0])) return false;
        if(isP(r + dx[1], c+ dy[1]) && !isX(r + dx[0],c+ dy[0])) return false;
        
        return true;
    }
    
    private boolean checkDown(int r, int c){
        int[] dx = {0,0};
        int[] dy = {1,2};
        
        if(isP(r + dx[0], c + dy[0])) return false;
        if(isP(r + dx[1], c+ dy[1]) && !isX(r + dx[0],c+ dy[0])) return false;
        
        return true;
    }
    
    private boolean checkRightUp(int r, int c){
        if(isP(r + 1, c - 1) && (!isX(r+1,c) || !isX(r,c-1))) return false;
        return true;
    }
    private boolean checkLeftUp(int r, int c){
        if(isP(r - 1, c - 1) && (!isX(r-1,c) || !isX(r,c-1))) return false;
        return true;
    }
    private boolean checkRightDown(int r, int c){
        if(isP(r + 1, c + 1) && (!isX(r+1,c) || !isX(r,c+1))) return false;
        return true;
    }
    private boolean checkLeftDown(int r, int c){
        if(isP(r + 1, c + 1) && (!isX(r+1,c) || !isX(r,c+1))) return false;
        return true;
    }
    
    private boolean isP(int r, int c){
        return !OOB(r,c) && place[r].charAt(c) == 'P';
    }
    private boolean isX(int r, int c){
        return !OOB(r,c) && place[r].charAt(c) == 'X';
    }
    private boolean OOB(int r, int c){
        return r < 0 || c < 0 || r >= 5 || c >= 5;
    }
}
