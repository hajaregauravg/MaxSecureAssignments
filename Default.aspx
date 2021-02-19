<%@ Page Title="Home Page" Language="C#" MasterPageFile="~/Site.master" AutoEventWireup="true"
    CodeBehind="Default.aspx.cs" Inherits="WebApplication1._Default" %>

<%@ Register assembly="AjaxControlToolkit" namespace="AjaxControlToolkit" tagprefix="cc1" %>

<asp:Content ID="HeaderContent" runat="server" ContentPlaceHolderID="HeadContent">
     <script type="text/javascript">
         function showpass(check_box) {
             var spass = document.getElementById("<%=passwd.ClientID %>");

             if (check_box.checked) {
                 spass.setAttribute("type", "text");
             }
             else {
                 spass.setAttribute("type", "password");
             }

         }
         </script>
     <style type="text/css">
         .style1
         {
             width: 383px;
         }
         .style2
         {
             width: 311px;
         }
     </style>
</asp:Content>

<asp:Content ID="BodyContent" runat="server" ContentPlaceHolderID="MainContent">
    <table border="0">
            <tr>
                <td class="style2">
                    <h1>Hey There</h1><br />
                </td>
            </tr>
            <tr>
                <td class="style2">
                    <h3>Enter Your Log-in ID Here:</h3>
                </td>
                <td class="style1">
                    <asp:TextBox ID="TextBox1" runat="server" ValidationGroup="login" 
                        CausesValidation="True" Width="168px"></asp:TextBox><br/>
                </td>
                <td>
                 <asp:RequiredFieldValidator ID="RequiredFieldValidator1" 
                       runat="server" ControlToValidate ="TextBox1"
                       ErrorMessage="Please enter your username" 
                       InitialValue="Please enter your username" SetFocusOnError="True" 
                        ValidationGroup="login" ToolTip="Validation" ClientIDMode="Static" 
                        Display="Dynamic" EnableClientScript="False"></asp:RequiredFieldValidator>
                   
                    
                </td>
               
            </tr>
            <tr>
                <td class="style2">
                    <h3>Enter Your Password Here:</h3>
                </td>
                <td class="style1" >
                    <asp:TextBox ID="passwd" runat="server" TextMode="Password" 
                        ValidationGroup="login" CausesValidation="True" Width="168px"></asp:TextBox><br/>
                    <asp:CheckBox ID="chek" runat="server" OnClick="showpass(this);" 
                        oncheckedchanged="chek_CheckedChanged"></asp:CheckBox>
                    Show Password
                </td>
                <td>
                    <asp:RequiredFieldValidator ID="RequiredFieldValidator2" 
                       runat="server" ControlToValidate ="passwd"
                       ErrorMessage="Please enter your password" 
                       InitialValue="Please enter your password" SetFocusOnError="True" 
                        ValidationGroup="login" BackColor="#66FFFF" Display="Dynamic" 
                        EnableClientScript="False" ForeColor="Red"></asp:RequiredFieldValidator>
                </td>
                
            </tr>
            
            <tr>
                <td style="text-align: center" class="style2">
                    <asp:Button ID="btnclick" runat="server" Text="Click To Save data and Log-in" 
                        OnClick="btnclick_Click"  ValidationGroup="login" 
                        style="margin-right: 3px" Width="252px"/>
                </td>
                <td style="text-align: center" class="style1">
                    <asp:Button ID="change_user" runat="server" Text="Click to change username" 
                        type="submit" onclick="change_user_Click" Width="277px" />
                </td>
            </tr>
            <tr>
                <td style="text-align: center" class="style2">
                    <asp:Button ID="change_password" runat="server" Text="Click to change password" 
                        onclick="change_password_Click" Height="25px" Width="252px" />
                </td>
                <td style="text-align: center" class="style1">
                    <asp:Button ID="delete_button" runat="server" Text="Click to delete data" 
                        onclick="delete_button_Click" Width="281px" />
                </td>
            </tr>
            <tr>
                <td style="text-align: center" class="style2">
                    <asp:Button ID="stored_procedure_button" runat="server" 
                        Text="Click to insert by Stored Procedure" 
                        onclick="stored_procedure_button_Click" Height="24px" Width="255px" />     
                </td>
                <td style="text-align: center" class="style1">
                    <asp:Button ID="sp_delete_button" runat="server" 
                        Text="Click to delete by Stored Procedure" 
                        onclick="sp_delete_button_Click" Height="27px" Width="283px" />
                </td>
            </tr>
            <tr>
                <td style="text-align: center" class="style2">
                    <asp:Button ID="sp_update_login_button" runat="server" 
                        Text="Click to update Login_ID by Stored Procedure" 
                        onclick="sp_update_login_button_Click" Height="28px" 
                        style="margin-right: 0px" Width="260px" />
                </td>
                <td style="text-align: center" class="style1">
                    <asp:Button ID="sp_update_password_button" runat="server" 
                        Text="Click to update Password by Stored Procedure" 
                        onclick="sp_update_password_button_Click" Width="289px"></asp:Button>
                </td>
            </tr>
            <tr>
                <td colspan="3">
                    <asp:ValidationSummary ID="ValidationSummary1" runat="server" DisplayMode ="BulletList" ShowSummary ="true" HeaderText="Errors:" />
                </td>
            </tr>
            <tr>
                <td colspan="3">
                    <asp:Image ID="Image1" runat="server" Width="720" Height="400" imageUrl="~/Images/1800x1200_cat_relaxing_on_patio_other.jpg"></asp:Image>
                    
                </td>
            </tr>
        </table>
         
         
</asp:Content>
