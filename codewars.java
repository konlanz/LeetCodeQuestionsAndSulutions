import java.util.Arrays;

// Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order. Essentially, rearrange the digits to create the highest possible number.

// Examples:
// Input: 42145 Output: 54421

// Input: 145263 Output: 654321

// Input: 123456789 Output: 987654321

public class DescendingOrder {
    public static int sortDesc(final int num) {
      //Your code
      
        String numString = Integer.toString(num);
        String[] numArray = numString.split("");
        Arrays.sort(numArray);
        StringBuilder sb = new StringBuilder();
        for (int i = numArray.length - 1; i >= 0; i--) {
            sb.append(numArray[i]);
        }
        return Integer.parseInt(sb.toString());

    }

    public static void main(String[] args) {
        System.out.println(sortDesc(42145));
        System.out.println(sortDesc(145263));
        System.out.println(sortDesc(123456789));
    }
  }