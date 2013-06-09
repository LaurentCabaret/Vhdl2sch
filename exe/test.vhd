----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    16:46:08 05/02/2013 
-- Design Name: 
-- Module Name:    Global - Behavioral 
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
use IEEE.STD_LOGIC_1164.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Global is
  port (  CLK      : in    std_logic;
          rW       : in    std_logic;   -- 0 --> read / 1 --> WRITE
          H_Add    : in    std_logic_vector (10 downto 0);
          V_Add    : in    std_logic_vector (10 downto 0);
          Label_e0 : out   std_logic_vector (20 downto 0);
          Label_e1 : inout std_logic_vector (20 downto 0);
          Label_e2 : inout std_logic_vector (20 downto 0);
          Label_e3 : inout std_logic_vector (20 downto 0);
          Label_e4 : inout std_logic_vector (20 downto 0)          
);
end Global;

architecture Behavioral of Global is
begin
  
end Behavioral;

