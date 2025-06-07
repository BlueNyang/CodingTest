class Solution {
    String[] jokaBabb = new String[]{"aya", "ye", "woo", "ma"};
    
    public boolean checkCanSpeak(String word) {
        for (String j: jokaBabb){
            if (word.length() == 0) return true;
            if (word.startsWith(j)){
                return checkCanSpeak(word.substring(j.length()));
            }
        }
        return false;
    }
    
    public int solution(String[] babbling) {
        int answer = 0;
        for (String b: babbling) {
            if (checkCanSpeak(b)) {
                answer++;
            }
        }
        return answer;
    }
}