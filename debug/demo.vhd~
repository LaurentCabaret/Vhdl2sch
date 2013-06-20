----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    22:23:14 05/29/2013 
-- Design Name: 
-- Module Name:    InputGate - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
USE ieee.std_logic_unsigned.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity InputGate is
  Port ( Clk            : in  STD_LOGIC;
         PxClk          : in  STD_LOGIC;
         PxVal          : in  STD_LOGIC;
         PxValOut       : out  STD_LOGIC;
         Col           	: out    std_logic_vector (9-1 downto 0);
         Cal           	: out    std_logic_vector (Size-1 downto 0);
         Lig          	: out    std_logic_vector (0 to 12);
         StatusInner   	: out   std_logic;
         UpLeftCorner   : out   std_logic;	 
         FirstLine    	: out   std_logic;
         FirstRow	: out   std_logic;
         LastRow	: out   std_logic;
         LastPixel 	: out   std_logic			  
         );
end InputGate;

architecture Behavioral of InputGate is
  CONSTANT LargeurBits : integer :=9;
  CONSTANT HauteurBits : integer :=9;
  COMPONENT AccessManager IS

    generic (
      hBusSize : integer range 0 to 11;
      vBusSize : integer range 0 to 11;
      imgWidth : integer range 0 to 1920;
      imgHeight : integer range 0 to 1080
      );

    port (        
      C_Add             : in    std_logic_vector (hBusSize-1 downto 0);
      L_Add             : in    std_logic_vector (vBusSize-1 downto 0);
      StatusInner       : out   std_logic;
      UpLeftCorner      : out   std_logic;	 
      FirstLine         : out   std_logic;
      FirstRow	       : out   std_logic;
      LastRow	       	 : out   std_logic;
      LastPixel	       : out   std_logic
      );

  END COMPONENT;

  signal CleanPxClk : std_logic :='0';
  SIGNAL C_Add :  std_logic_vector (LargeurBits-1 downto 0) := (others=>'0');
  SIGNAL L_Add :  std_logic_vector (HauteurBits-1 downto 0) := (others=>'0');
  SIGNAL SigLastRow :  std_logic := '0';
  SIGNAL SigLastPixel :  std_logic := '0';
  
begin
  AM1: AccessManager GENERIC MAP(
    hBusSize => LargeurBits,
    vBusSize => HauteurBits,
    imgWidth => 512,
    imgHeight => 512
    )
    PORT MAP(
      C_Add 				=> C_Add,
      L_Add 				=> L_Add,
      StatusInner 		=> StatusInner,
      UpLeftCorner 		=> UpLeftCorner,
      FirstLine 			=> FirstLine,						
      FirstRow 			=> FirstRow,
      LastRow 				=> SigLastRow ,
      LastPixel			=> SigLastPixel
      );


  PxClkEventManager: process(Clk)
    variable flag : std_logic := '1';
  begin
    if Clk'Event and Clk='1' then 
      if (PxClk = '1' and flag = '0') then CleanPxClk <='1';
                                           flag:='1';
      elsif PxClk = '0' then flag:='0'; 
                             CleanPxClk <='0';
      elsif PxClk = '1' and flag = '1' then CleanPxClk <='0';
                                            flag:='1';
      end if;
    end if;
  end process;

  PixelCounter: process(Clk)
    variable flag : std_logic := '1';
  begin
    if Clk'Event and Clk='1' then 
      if CleanPxClk = '1' then 
        if SigLastRow='1' then C_Add <= (others=>'0');
                               if SigLastPixel ='1' then L_Add <=  (others=>'0');
                               else L_Add <= L_Add + 1;
                               end if;
        else C_Add <= C_Add + 1;												
        end if;
      end if;
    end if;
  end process;

  Col <= C_Add;
  Lig <= L_Add;
  LastRow <= SigLastRow;
  LastPixel <= SigLastPixel;

  PxValOut <= PxVal; 
end Behavioral;

