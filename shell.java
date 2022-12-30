import java.util.Scanner;
import java.util.Arrays;
public class shellosort {
    public static void main(String[] args) {
        Scanner scr = new Scanner(System.in);
        System.out.print("Enter the size : ");
        int size = scr.nextInt();
        int i;
        int[] arr1= new int[size];
        for(i=0;i<size;i++){
            System.out.print("Enter the element "+(i+1)+" :");
            arr1[i]= scr.nextInt();
        }
        shell(size,arr1);
        System.out.println(Arrays.toString(arr1));
    }
    static void shell(int size,int[] arr){
        int i,j,gap,tem;
        for(gap = size/2;gap>=1;gap = gap/2){
            for(j=gap;j<size;j++){
                for(i=j-gap;i>=0;i=i-gap){
                    if(arr[i]>arr[i+gap]){
                       swap(i,i+gap,arr);
                    }
                }
            }
        }
    }
    static void swap(int a,int b,int[] arr){
        int tem = arr[a];
        arr[a]= arr[b];
        arr[b]= tem;
    }
}
