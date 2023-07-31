import java.util.Scanner;

    public static void main(String [] args)
    {
        Scanner input = new Scanner (System.in);
        System.out.print("Enter an integer: ");
        int number = input.nextInt();
        System.out.println("You entered " + number);
        System.out.print("\nEnter text : ");
        String T = input.next();
        System.out.print("\nText : "+T);
    }

