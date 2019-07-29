import java.util.*;
public class Flames{
    public static void main(String[] args){
        ArrayList<Character> object = new ArrayList<>();
        Scanner scan = new Scanner(System.in);
        object.add('f');
        object.add('l');
        object.add('a');
        object.add('m');
        object.add('e');
        object.add('s');
        int index, copy, local;
        Flames obj = new Flames();
        String yourName, partnerName;
        System.out.println("Enter your name");
        yourName = scan.next();
        System.out.println("Enter your partner name");
        partnerName = scan.next();
        yourName = yourName.toLowerCase();
        partnerName = partnerName.toLowerCase();
        int count = obj.getCount(yourName, partnerName);
    //    System.out.println(count);
        char flameChar = obj.getFlameChar(count, object);
    //    System.out.println("char = "+flameChar);
        String flameString = obj.getFlameString(flameChar);
        System.out.print("\n\n\n");
        System.out.println(flameString);
    }
    String getFlameString(char flameChar){
        if(flameChar == 'f')
            return "FRIEND";
        else if(flameChar == 'l')
            return "LOVE";
        else if(flameChar == 'a')
            return "AFFECTION";
        else if(flameChar == 'm')
            return "MARRIAGE";
        else if(flameChar == 'e')
            return "ENEMY";
        else if(flameChar == 's')
            return "SISTER";
        return "-1";
    }
    char getFlameChar(int count, ArrayList<Character> object){
        int index, copy, local;
        local = count;
        if(local>object.size()){
            while(local > object.size()){
                local = local - object.size();
            }
           index = local;
        }
        else 
            index = local;
        index -= 1;
        for(int i=0; i<5; i++){
            object.remove(index);
        //    System.out.println(object);  
            index += count;
            if(index > object.size()){
                while(index > object.size()){
                    index = index - object.size();
                }
            index -= 1;
            }
            else
                index -= 1;
        }
        char flamecharacter = object.get(0);
      //  System.out.println(object);
        return flamecharacter;
    }
    int getCount(String str1, String str2){
        int count = 0, match = 0;
        count = str1.length() + str2.length();
        char[] urName = new char[str1.length()];
        char[] partnerName = new char[str2.length()];
        for(int i=0;  i<str1.length(); i++){
            urName[i] = str1.charAt(i);
        }
        for(int i=0;  i<str2.length(); i++){
            partnerName[i] = str2.charAt(i);
        }
        for(int i=0; i<urName.length; i++){
            for(int j=0; j<partnerName.length; j++){
                if(urName[i] == partnerName[j]){
                    urName[i] = '@';
                    partnerName[j] = '@';
                    match += 2;
                    break;
                }
            }
        }
        count = count - match;
        return count;
    }
}