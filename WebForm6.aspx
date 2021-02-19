<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm6.aspx.cs" Inherits="WebApplication1.WebForm6" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head id="Head1" runat="server">
    <title></title>
</head>

<body>
    <form id="form1" runat="server">
    <table border="0">
            <tr>
                <td>
                    <h1>Hey There</h1><br />
                </td>
            </tr>
            <tr>
                <td>
                    <h3>Enter Your Log-in ID Here:</h3>
                </td>
                <td>
                    <asp:TextBox ID="TextBox1" runat="server"></asp:TextBox><br/>
                </td>
            </tr>
            <tr>
                <td>
                    <h3>Enter Your Password Here:</h3>
                </td>
                <td >
                    <asp:TextBox ID="passwd" runat="server" TextMode="Password" ></asp:TextBox><br/>
                    <asp:CheckBox ID="CheckBox1" runat="server" OnClick="showpass(this);"></asp:CheckBox>
                 Show Password

                 <script type="text/javascript">
                     function showpass(check_box) {
                         var spass = document.getElementById("<%=passwd.ClientID %>");

                         if (check_box.checked)
                             spass.setAttribute("type", "text");
                         else
                             spass.setAttribute("type", "password");
                     }

                </script>

                </td>
            </tr>
        
            <tr>
                <td>
                    <asp:Button ID="sp_insert_Button" runat="server" Text="Click to save data" 
                        onclick="sp_insert_Button_Click" />
                </td>
            </tr>
        </table>
    </form>
</body>
</html>
