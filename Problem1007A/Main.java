import java.util.*;

public class Main{

    public static void main(String[] args){
        int aux = 1;
        int cont = 0;
        int res = 0;
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int arr[] = new int[num];
        sc.nextLine();

        for(int i = 0; i < num; i++){
            arr[i] = sc.nextInt();
        }

        Arrays.sort(arr);

        while (aux < num) {
            if (arr[cont] < arr[aux]) {
                cont++;
                aux++;
                res++;
            }
            else {
                aux++;
            }
        }

        System.out.println(res);
    }

}
