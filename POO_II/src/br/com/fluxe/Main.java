package br.com.fluxe;

public class Main {

	public static void main(String[] args) throws InterruptedException {
		
		Program_Status status = Program_Status.RUNNING;
		Menu_Options option;
		
		UI_Helper.showLogo();
		
		
		while(!status.equals(Program_Status.EXITED)) {
			UI_Helper.showMenu();
			option = Input_Handler.menu_input();
			System.out.println(option);
			switch(option) {
				case ADD_USER:
					break;
				case ALTER_USER_DATA:
					break;
				case ALTER_PASSWORD:
					break;
				case ADD_ENTRY_FLUXE:
					break;
				case ADD_EXIT_FLUXE:
					break;
				case MAKE_FINANCIAL_REPORT:
					break;
				case EXIT:
					break;
				default:
					break;
			}
		}
	}
}
