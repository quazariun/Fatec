package br.com.fluxe;

import java.util.Scanner;
import java.util.concurrent.TimeUnit;

public class Input_Handler {


	public static Menu_Options menu_input() throws InterruptedException {
		@SuppressWarnings("resource")
		Scanner user_input = new Scanner(System.in);
		int option;
		
		while(true) {
			try {
				option = user_input.nextInt();
				
				if(option < 1 || option > Menu_Options.values().length) {
					System.out.println("Você digitou um número fora do escopo, tente novamente.");
					TimeUnit.SECONDS.sleep(3);
					UI_Helper.showMenu();
					continue;
				} else {
					break;
				}
			} catch (Exception e) {
				System.out.println("Ocorreu um erro: " + e);
				System.out.println("Por favor, digite novamente");
				TimeUnit.SECONDS.sleep(4);
				user_input.next();
				System.out.println();
				UI_Helper.showMenu();
			}		
		}
		
		return Menu_Options.values()[option-1];
	}
	
}
