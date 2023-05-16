class Solution {
    public int solution(String s) {
        int answer = 0;
        int memo = 0;
        String[] arr = s.split(" ");
        
        for (int i =0; i<arr.length; i++){
            if (arr[i].equals("Z")){
                answer -= memo;
            } else {
                memo = Integer.parseInt(arr[i]);
                answer += memo;
            }
        }
        
        return answer;
    }
}