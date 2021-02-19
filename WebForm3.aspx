<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm3.aspx.cs" Inherits="WebApplication1.WebForm3" %>

<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
</head>
<body>
    <form id="form1" runat="server">
    <div>
        <table>
            <tr>
                <td>
                    <h1>Hey Friend!!</h1>
                </td>
            </tr>

            <tr>
                <td>
                    Enter your username:
                </td>
                <td>
                    <asp:TextBox ID="user_name_TextBox" runat="server"></asp:TextBox><br/>
                </td>
            </tr>
            <tr>
                <td>
                    Enter the new password:
                </td>
                <td>
                    <asp:TextBox ID="new_password_TextBox" runat="server" TextMode="Password"></asp:TextBox><br/>
                    <asp:CheckBox ID="CheckBox1" runat="server" OnClick="showpass(this);"/> Show Password
                    <script type="text/javascript">
                        function showpass(check_box) {
                            var spass = document.getElementById("<%=new_password_TextBox.ClientID %>");

                            if (check_box.checked) {
                                spass.setAttribute("type", "text");
                            }
                            else {
                                spass.setAttribute("type", "password");
                            }

                        }
         </script>
                </td>
            </tr>
            <tr>
                <td>
                    <asp:Button ID="Button1" runat="server" Text="Click to change password" onclick="Button1_Click" />
                </td>
            </tr>
        </table>
    </div>
    </form>
</body>
</html>
