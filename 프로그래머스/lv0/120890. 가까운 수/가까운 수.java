class Solution {
    public int solution(int[] array, int n) {
        int answer = 0;
        int check = 10000;
        for (int i =0; i<array.length; i++){
            if (check > Math.abs(n - array[i])){
                check = Math.abs(n - array[i]);
                answer = array[i];
            } else if (check == Math.abs(n-array[i])){
                if (array[i] < answer){
                    answer = array[i];
                }
            }
        }
        return answer;
    }
}