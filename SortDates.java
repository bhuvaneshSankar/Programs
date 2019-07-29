import java.util.*;
public class SortDates{
    public static List sortDates(List<String> dates){
        TreeSet<String> ts = new TreeSet<>(new DefinedComparator());        // treeset with user defined comparator
        for(int i=0; i<dates.size(); i++){
            ts.add(dates.get(i).toString());
        }
        ArrayList<String> al = new ArrayList<>(ts);
        return al;
    }
    public static void main(String[] args){
        ArrayList<String> dateList = new ArrayList<>();
        dateList.add("01 Mar 2015");
        dateList.add("11 Apr 1996");
        dateList.add("22 Oct 2007");
        dateList.add("18 Oct 2007");
        dateList.add("22 Feb 1996");
        List<String> l = sortDates(dateList);
        dateList = new ArrayList<>(l);
        for(int i=0; i<dateList.size(); i++){
            System.out.println(dateList.get(i));
        }
    }
}
class DefinedComparator implements Comparator<String>{
    public int getYear(String s){
        int n=0;
        for(int i=7; i<=10; i++){
            int val = Character.getNumericValue(s.charAt(i))-10;            //for 'a' this function returns 10
            n = n*10 + val;
        }
        return n;
    }
    public int getDate(String s){
        int n=0;
        for(int i=0; i<=1; i++){
            int val = Character.getNumericValue(s.charAt(i))-10;
            n = n*10 + val;
        }
        return n;
    }
    public int getMonth(String s){
        String month = s.substring(3, 6);
        String[] allMonths = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
        for(int i=0; i<allMonths.length; i++){
            if(month.equals(allMonths[i]))
                return i;
        }
        return -1;
    }
    public int compare(String s1, String s2){
        int d1 = getDate(s1);
        int d2 = getDate(s2);
        int m1 = getMonth(s1);
        int m2 = getMonth(s2);
        int y1 = getYear(s1);
        int y2 = getYear(s2);
        if(y1<y2)
            return -1;
        else if(y1>y2)
            return 1;
        if(m1<m2)
            return -1;
        else if(m1>m2)
            return -1;
        if(d1<d2)
            return -1;
        else if(d1>d2)
            return 1; 
        return 0;
    }
}