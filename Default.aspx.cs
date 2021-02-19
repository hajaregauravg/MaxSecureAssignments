using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.SqlClient;
using System.Diagnostics;

namespace WebApplication1
{
    public partial class _Default : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {

        }

        protected void btnclick_Click(object sender, EventArgs e)
        {
            RequiredFieldValidator1.Validate();
            RequiredFieldValidator2.Validate();
            Page.Validate();
            Debug.WriteLine("Page.IsValid= " + Page.IsValid);
            if (RequiredFieldValidator1.IsValid && RequiredFieldValidator2.IsValid && Page.IsValid)
            {
                string insert = "";
                SqlConnection con = new SqlConnection(@"Data Source=TEST\MSSQLSERVER1; Initial Catalog= My_database; AttachDbFilename=C:\Program Files\Microsoft SQL Server\MSSQL14.MSSQLSERVER1\MSSQL\DATA\My_database.mdf;Integrated Security=True");
                insert = "INSERT INTO creds(Login_ID, Password) VALUES(@Login_ID, @Password)";
                SqlCommand cmd = new SqlCommand(insert, con);
                cmd.Parameters.AddWithValue("@Login_ID", TextBox1.Text);
                cmd.Parameters.AddWithValue("@Password", passwd.Text);
                con.Open();
                int i = cmd.ExecuteNonQuery();

                con.Close();

                if (i != 0)
                {

                    Debug.WriteLine("Data Saved");
                }
                Server.Transfer("WebForm1.aspx");
            }
            else
            {
                Debug.WriteLine("Please enter both user-name and password.");
            }
        }

        protected void chek_CheckedChanged(object sender, EventArgs e)
        {
                
        }

        protected void change_user_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm2.aspx");
        }

        protected void change_password_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm3.aspx");
        }

        protected void delete_button_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm4.aspx");
        }

        protected void stored_procedure_button_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm6.aspx");
        }

        protected void sp_delete_button_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm5.aspx");
        }

        protected void sp_update_login_button_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm7.aspx");
        }

        protected void sp_update_password_button_Click(object sender, EventArgs e)
        {
            Server.Transfer("WebForm8.aspx");
        }
    }
}
